<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Kodak;

use PHPExiftool\Driver\AbstractTag;

class PreviewImageLength extends AbstractTag
{

    protected $Id = 2;

    protected $Name = 'PreviewImageLength';

    protected $FullName = 'Kodak::Scrn';

    protected $GroupName = 'Kodak';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Kodak';

    protected $g2 = 'Image';

    protected $Type = 'int32u';

    protected $Writable = false;

    protected $Description = 'Preview Image Length';

    protected $flag_Permanent = true;

}
