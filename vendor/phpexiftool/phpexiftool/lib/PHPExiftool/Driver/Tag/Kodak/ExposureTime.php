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

class ExposureTime extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'ExposureTime';

    protected $FullName = 'mixed';

    protected $GroupName = 'Kodak';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Kodak';

    protected $g2 = 'mixed';

    protected $Type = 'mixed';

    protected $Writable = false;

    protected $Description = 'Exposure Time';

    protected $flag_Permanent = true;

}
