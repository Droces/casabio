<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Casio;

use PHPExiftool\Driver\AbstractTag;

class PreviewImageStart extends AbstractTag
{

    protected $Id = 4;

    protected $Name = 'PreviewImageStart';

    protected $FullName = 'Casio::Type2';

    protected $GroupName = 'Casio';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Casio';

    protected $g2 = 'Camera';

    protected $Type = 'int32u';

    protected $Writable = true;

    protected $Description = 'Preview Image Start';

    protected $local_g2 = 'Image';

    protected $flag_Permanent = true;

    protected $flag_Protected = true;

}
