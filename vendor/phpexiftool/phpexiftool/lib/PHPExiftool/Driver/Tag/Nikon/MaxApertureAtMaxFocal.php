<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Nikon;

use PHPExiftool\Driver\AbstractTag;

class MaxApertureAtMaxFocal extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'MaxApertureAtMaxFocal';

    protected $FullName = 'mixed';

    protected $GroupName = 'Nikon';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Nikon';

    protected $g2 = 'Camera';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'Max Aperture At Max Focal';

    protected $flag_Permanent = true;

}
